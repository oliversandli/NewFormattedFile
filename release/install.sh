#!/usr/bin/env bash

echo "Compiling source & installing..."
g++ nff.cpp -o /usr/local/bin/nff
echo "Creating config directory and templates..."
if [ $XDG_DATA_PATH ]
then
  mkdir $XDG_DATA_PATH/nff/
  cp -r templates $XDG_DATA_PATH/nff/templates/
else
  if [ ~/.config ]
  then
    mkdir ~/.config/nff/
    cp -r templates ~/.config/nff/templates/
  else
    echo "Error: cannot find '$XDG_DATA_PATH' or '~/.config'
    echo "Create templates directory manually or uninstall nff."
    exit 1
  fi
fi
echo "DONE"
