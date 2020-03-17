#!/usr/bin/env bash

echo "Removing '/usr/local/bin/nff' ..."
rm /usr/local/bin/nff
if [ $XDG_DATA_HOME ]
then
  echo "Removing $XDG_DATA_HOME/nff/"
  rm -rf $XDG_DATA_HOME/nff/
else
  if [ ~/.config ]
  then
    echo "Removing '~/.config/nff/' ..."
    rm -rf ~/.config/nff/
  else
    echo "Error: cannot find '$XDG_DATA_PATH' or '~/.config'"
    exit 1
  fi
fi
echo "DONE"
