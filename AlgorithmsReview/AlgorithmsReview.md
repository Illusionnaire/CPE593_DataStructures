# Algorithms Review
The following is a document designed to help review the fundamental algorithms that have been learned in this class as well as give an explanation to how they work and their order of complexity.

Beyond the scope of this document, a student should also know how to find the order of complexity of a given algorithm by him/herself.
---

## Greatest Common Denominator
* The greatest common denominator algorithm is given two numbers as parameters and finds the greatest common denominator between them. This is done efficiently using modulus and the Euclidean algorithm which states that the greatest common denominator does not change when you modulus the values and use the remainders as the new values. This slowly decreases the values until a number is found that goes evenly into both.

### Code
Complexity order: O(log(n)) since each division cuts the value.

    int GCD(a, b){
        if(b == 0){
            return a;
        }
        return (b, a % b)
    }

