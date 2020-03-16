#!/usr/bin/env bash

echo "Compiling source & installing..."
g++ nff.cpp -o /usr/local/bin/nff
echo "Creating config directory..."
mkdir ~/.config/nff/
echo "Copying default templates..."
mkdir ~/.config/nff/templates/
cp  -r templates ~/.config/nff/templates/
echo "DONE."
