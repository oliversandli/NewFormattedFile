#!/usr/bin/env bash

echo "Compiling source & installing..."
g++ nff.cpp -o /usr/local/bin/nff
echo "Creating config directory and templates..."
if [ $XDG_CONFIG_HOME ]
then
  mkdir $XDG_CONFIG_HOME/nff/
  cp -r templates $XDG_CONFIG_HOME/nff/templates/
  echo "Installed templates in '$XDG_CONFIG_HOME/nff/templates/'"
else
  if [ -d ~/.config ]
  then
    mkdir ~/.config/nff/
    cp -r templates ~/.config/nff/templates/
    echo "Installed templates in '~/.config/nff/templates/'"
  else
    echo "Error: cannot find '$XDG_CONFIG_HOME' or '~/.config'"
    echo "Create templates directory manually or uninstall nff."
    exit 1
  fi
fi
echo "DONE"
