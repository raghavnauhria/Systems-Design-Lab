// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/02/Add4.tst

load Mults.hdl,
output-file Mults.out,
compare-to Mults.cmp,
output-list a%B1.4.1 b%B1.4.1 c%B1.1.1 out%B1.8.1;

set a %B0000,
set b %B0000,
set c 0,
eval,
output;

set a %B0000,
set b %B0111,
set c 0,
eval,
output;

set a %B1100,
set b %B0101,
set c 0,
eval,
output;

set a %B1101,
set b %B0100,
set c 0,
eval,
output;
