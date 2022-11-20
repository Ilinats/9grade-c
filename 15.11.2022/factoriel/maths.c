long fact(int number) {
    long result = 1; 

    while(number > 0)
    {
        result *= number;
        number --; 
    }

    return result;
}