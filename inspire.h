
/**
 * @file inspire.h
 * @brief Obtain BibTeX information from iNSPIRE web site
 * @author So Chigusa
 * @date 2019/08/14
 */

#ifndef INSPIRE_H
#define INSPIRE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Inspire {
 private:
  std::string author;
  std::string ofname;
 public:
  Inspire(char *, char *);
  void split(std::vector<std::string> &, const std::string &buf, char sep);
  void split(std::vector<std::string> &, const std::string &buf, const std::string &sep);
  void get();
};

Inspire::Inspire(char *arg_author, char *arg_out)
: author(arg_author), ofname(arg_out) {
}

void Inspire::split(std::vector<std::string> &v, const std::string &buf, char sep) {
  v.resize(0);
  std::stringstream ss(buf);
  std::string mbuf;
  while(getline(ss, mbuf, sep)) { if(mbuf != "") v.push_back(mbuf); }
}

void Inspire::split(std::vector<std::string> &v, const std::string &arg_buf, const std::string &sep) {
  std::string buf = arg_buf;
  auto delim = buf.find(sep);
  while(delim != std::string::npos) {
    buf.replace(delim, sep.length(), ";");
    delim = buf.find(sep);
  }
  split(v, buf, ';');
}

void Inspire::get() {
  std::ofstream ofs(ofname);
  std::string url = "search?p=author:"+author+" AND collection:citeable&rg=250";
  system(("wget \"https://inspirehep.net/"+url+"\"").c_str());

  std::vector<std::string> v, vu;
  std::ifstream ifs(url);
  std::string buf((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
  split(v, buf, "</a>");
  for(int i = 0; i < v.size(); ++i) {
    if(v[i].find("BibTeX") != std::string::npos) {
      split(vu, v[i], '"');
      system(("wget \""+vu[1]+"\"").c_str());
    }
    std::ifstream ifs("hx");
    if(ifs) {
      std::string buf((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
      auto p1 = buf.find("@article");
      auto p2 = buf.find("</pre>");
      std::string bib(buf.substr(p1, p2-p1));
      std::cout << bib << std::endl;
      ofs << bib << std::endl;
      std::remove("hx");
    }
  }
  std::remove(url.c_str());
  ofs.close();
}

#endif
