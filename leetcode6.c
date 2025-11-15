int lengthOfLastWord(char * s){
    int length = 0;
    int i = 0;

    // Move to end of string
    while (s[i] != '\0')
        i++;

    // Skip spaces from the end
    i--;
    while (i >= 0 && s[i] == ' ')
        i--;

    // Count characters of last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
