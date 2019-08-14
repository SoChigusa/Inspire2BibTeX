# Obtain BibTeX from iNSPIRE #

## Description ##

Obtain BibTeX information from iNSPIRE web site for all papers of a given author.
**Now the maximum number of papers is 250 from the most recent.**

## Preparation and compilation ##

This code accesses inspire using `wget` command.
Please use OS X / Linux with `wget` installed.
For OS X, we can install the command using `homebrew` as

``` shell
brew install wget
```

For the compilation, just type

``` shell
make
```

## How to use ##

First go to the iNSPIRE personal page for the author.
When you click the link for the all papers (citeable or published only), the URL is something like

``` html
http://inspirehep.net/search?p=author%3A[Author name]%20AND%20collection%3Aciteable
```

Please extract the information `[Author name]` and input as

``` shell
./Inspire2BibTeX [Author name] [Output file]
```

All the papers of the author will be summarized in the BibTeX format in `[Output file]`.
