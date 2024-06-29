#!/bin/bash

set -eu -o pipefail

make;

# Note: The expected colours  where obtained in Gimp, by setting the top layer's
# blend space and composite space to **Perceptual**.
# Perceptual *is not* the default space used  by Gimp but I'm not buff enough on
# colour theory to know how either space work or how they would affect the code.
# For now, I simply went with the math that was the most instinctive to me.
#
# Conversely, the  opposite  Normal  blend  operation  would  need  to have  its
# its top layer's  composite space set to  Perceptual too, in order to yield the
# original colour.


#                              #Bottom     #Top        #Expected
# Greyscales
echo && ./colour-to-alpha.out "#ff808080" "#ffffffff" "#7f000000"
echo && ./colour-to-alpha.out "#ff808080" "#ff000000" "#7fffffff"
echo && ./colour-to-alpha.out "#ff808080" "#80ffffff" "#bf555555"
echo && ./colour-to-alpha.out "#ff808080" "#80000000" "#bfaaaaaa"

# Red, orange and yellow
echo && ./colour-to-alpha.out "#ffff0000" "#ffff8000" "#ffff0000"
echo && ./colour-to-alpha.out "#ffffff00" "#ffff8000" "#ffffff00"
echo && ./colour-to-alpha.out "#ffff8000" "#ffff8000" "#00ff8000"
echo && ./colour-to-alpha.out "#ffffcc00" "#ffff8000" "#99ffff00"
echo && ./colour-to-alpha.out "#ffff4400" "#ffff8000" "#76ff0000"

# Randomly selected colours at varying opacity
echo && ./colour-to-alpha.out "#be41b22c" "#43286639" "#a545be26"
echo && ./colour-to-alpha.out "#f2c90016" "#d9634e6c" "#f2c90016"
echo && ./colour-to-alpha.out "#9feff58a" "#ffb05c3a" "#96f3ff8f"
