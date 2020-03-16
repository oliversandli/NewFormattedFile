#!/usr/bin/env bash

echo "Compiling source & installing..."
g++ nffv2.cpp -o /usr/local/bin/nff
echo "Creating config directory..."
mkdir ~/.config/nff/
echo "Copying default templates..."
cp templates ~/.config/nff/templates/
echo "DONE."
