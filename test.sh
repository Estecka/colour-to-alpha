#!/bin/bash

set -eu -o pipefail

make;

echo;
echo "         Input         Blend-space  Result        Expected      Diff";
# Blend-space here  corresponds to both the blend space  and the composite space
# of the top layer in Gimp.
#
# Linear is the default  in gimp, but getting  the correct result  here requires
# the  colour  codes  to be converted  back and forth  between  the two  spaces,
# which I might be doing incorrectly.
#
# Perceptual requires  no such conversion, but requires  the layer's settings to
# be adjusted in Gimp.


#                                                          Expected      Expected
#                              Bottom        Top           Linear        Perceptual
# Greyscales
echo && ./colour-to-alpha.out "808080@1.00" "ffffff@1.00" "000000@.784" "000000@.498"
echo && ./colour-to-alpha.out "808080@1.00" "000000@1.00" "ffffff@.216" "ffffff@.502"
echo && ./colour-to-alpha.out "808080@1.00" "ffffff@.500" "626262@.890" "555555@.749"
echo && ./colour-to-alpha.out "808080@1.00" "000000@.500" "a1a1a1@.608" "aaaaaa@.753"

# Red to yellow gradient
echo && ./colour-to-alpha.out "ff0000@1.00" "ff8000@1.00" "ff0000@1.00" "ff0000@1.00"
echo && ./colour-to-alpha.out "ff4400@1.00" "ff8000@1.00" "ff0000@.733" "ff0000@.471"
echo && ./colour-to-alpha.out "ff8000@1.00" "ff8000@1.00" "ff8000@.000" "ff8000@0.00"
echo && ./colour-to-alpha.out "ffcc00@1.00" "ff8000@1.00" "ffff00@.494" "ffff00@.600"
echo && ./colour-to-alpha.out "ffff00@1.00" "ff8000@1.00" "ffff00@1.00" "ffff00@1.00"

# Randomly selected colours at varying opacity
echo && ./colour-to-alpha.out "41b22c@.745" "286639@.267" "45bd29@.624" "45be2a@.643"
echo && ./colour-to-alpha.out "41b22c@1.00" "286639@1.00" "5bf900@.384" "5aff1f@.498"
echo && ./colour-to-alpha.out "c90016@.949" "634e6c@.851" "c90016@.949" "c90016@.949"
echo && ./colour-to-alpha.out "eff58a@.623" "b05c3a@1.00" "f5ff90@.561" "f3ff8f@.584"
echo && ./colour-to-alpha.out "008040@.755" "00ff00@.770" "004546@.631" "003068@.463"
