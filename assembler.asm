add $t0 $t1 $t2
sw $t0 0($s0)
lw $t3 0($s0)
addi $t0 $s1 5
j L1
sub $t0 $t1 $t3
sll $s3 $t0 2
slt $s0 $t0 $t1
and $s2 $t0 $t1
or $s1 $t0 $t1
