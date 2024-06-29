#!/bin/bash

set -eu -o pipefail

make;

echo;
echo "         Input         Blend-space  Result        Expected      Diff";
# Linear blend space is the default in GIMP, but requires the colour codes to be
# converted  back and forth between the two  in the code. Perceptual blend space
# requires no  conversion, but in order to observe  the expected result in GIMP,
# the  top layer's blend-space and composite-space must both  manually be set to
# Perceptual.


#                              #Bottom        Top           Expected        Expected
#                                                           Perceptual      Linear
# Greyscales
echo && ./colour-to-alpha.out "#808080@1.00" "#ffffff@1.00" "#000000@.498" "#000000@.784"
echo && ./colour-to-alpha.out "#808080@1.00" "#000000@1.00" "#ffffff@.502" "#ffffff@.216"
echo && ./colour-to-alpha.out "#808080@1.00" "#ffffff@.500" "#555555@.749" "#626262@.890"
echo && ./colour-to-alpha.out "#808080@1.00" "#000000@.500" "#aaaaaa@.753" "#a1a1a1@.608"

# Red, orange and yellow
# echo && ./colour-to-alpha.out "#ffff0000" "#ffff8000" "#ffff0000"
# echo && ./colour-to-alpha.out "#ffffff00" "#ffff8000" "#ffffff00"
# echo && ./colour-to-alpha.out "#ffff8000" "#ffff8000" "#00ff8000"
# echo && ./colour-to-alpha.out "#ffffcc00" "#ffff8000" "#99ffff00"
# echo && ./colour-to-alpha.out "#ffff4400" "#ffff8000" "#76ff0000"

# # Randomly selected colours at varying opacity
# echo && ./colour-to-alpha.out "#be41b22c" "#43286639" "#a545be26"
# echo && ./colour-to-alpha.out "#f2c90016" "#d9634e6c" "#f2c90016"
# echo && ./colour-to-alpha.out "#9feff58a" "#ffb05c3a" "#96f3ff8f"
