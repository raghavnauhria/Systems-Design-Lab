// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/02/Add4.tst

load Add4.hdl,
output-file Add4.out,
compare-to Add4.cmp,
output-list a%B1.4.1 b%B1.4.1 c%B1.1.1 out%B1.4.1 carry%B3.1.3;

set a %B0000,
set b %B0000,
set c 0,
eval,
output;

set a %B0001,
set b %B1111,
set c 0,
eval,
output;

set a %B1111,
set b %B1111,
set c 0,
eval,
output;

set a %B1010,
set b %B0101,
set c 0,
eval,
output;

set a %B0011,
set b %B0000,
set c 0,
eval,
output;

set a %B0001,
set b %B1001,
set c 0,
eval,
output;
