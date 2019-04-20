Program Sicily1014(input, output);

Function sumdigit(n: Integer; base: Integer): Integer;
Var
    res: Integer;
Begin
    res := 0;
    While n > 0 Do
    Begin
        res := res + (n Mod base);
        n := n Div base;
    End;
    sumdigit := res;
End;

Var 
    i: Integer;
Begin
    For i := 1000 To 9999 Do
        If (sumdigit(i, 10) = sumdigit(i, 16)) And (sumdigit(i, 10) = sumdigit(i, 12)) Then
            Writeln(i);
End.