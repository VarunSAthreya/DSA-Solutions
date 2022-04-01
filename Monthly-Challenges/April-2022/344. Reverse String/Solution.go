func reverseString(s []byte)  {
    i:=0
    j:=len(s)-1

    for i < j {
        temp:= s[i]
        s[i] = s[j]
        s[j] = temp
        i+=1
        j-=1
    }
}
