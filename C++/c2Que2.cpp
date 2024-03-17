int toggleTheMiddle(int n) {
    // Count the number of bits in n
    int numberOfBits = log2(n) + 1;
    
    // Check if the number of bits is odd or even
    if (numberOfBits % 2 == 1) {
        // If odd, toggle the middle bit by XORing with 1 shifted to the middle position
        return n ^ (1 << (numberOfBits / 2));
    } else {
        // If even, toggle both middle bits by XORing with 1 shifted to the middle positions
        return n ^ ((1 << (numberOfBits / 2)) | (1 << (numberOfBits / 2 - 1)));
    }
}