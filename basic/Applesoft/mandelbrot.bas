5 REM SOURCE: https://github.com/CodingTrain/Nebula-AppleSoft-Basic
10 HGR2
20 DIM NUMS(10)
30 NUMS(0) =  1 : NUMS(1) = 2 : NUMS(2) = 5 : NUMS(3) = 6 : NUMS(4) = 7 : NUMS(5) = 0
40 FOR I1 = 0 TO 279 : FOR J1 = 0 TO 96
50 X = I1 / 280 * 3 - 2
60 Y = J1 / 191 * 2 - 1
70 A1 = X : B1 = Y : N = 0
80 A2 = A1 * A1 - B1 * B1 + X
90 B1 = 2 * A1 * B1 + Y
100 N = N + 1
110 A1 = A2
120 IF A1*A1 + B1*B1 < 4 AND N < 10 THEN GOTO 80
130 COL = NUMS(INT(N/2))
140 HCOLOR = COL
150 IF COL THEN HPLOT I1,J1 : HPLOT I1, 191-J1
160 NEXT : NEXT
