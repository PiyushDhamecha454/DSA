# 1. Infix to Prefix Conversion
### Algorithm
* Reverse the infix expression.
* Replace ( with ) and vice versa.
* Use a stack to convert the modified expression to postfix notation:
    * If the character is an operand, add it to the result.
    * If the character is a right parenthesis `)`, push it to the stack.
    * If the character is a left parenthesis `(`, pop from the stack to the result until `)` is found.
    * If the character is an operator, pop from the stack to the result while the operator at the top of the stack has higher or equal precedence.
    * Push the current operator to the stack.
Pop all operators from the stack to the result.
Reverse the result string to get the final prefix expression.
### Dry Run Example
**Infix Expression** : `(A+B)*C-(D/E)`
1. Reverse: `)E/D(-C*)B+A(`
2. Replace: `(E/D)-C*(B+A)`
3. Convert to postfix: `+AB*C/-DE`
4. Reverse postfix to get prefix: `-*+ABC/DE`

### Pseudocode
```cpp
function infixToPrefix(infix):
    reverse(infix)
    swap '(' with ')' and vice versa
    stack = empty stack
    result = empty string
    
    for each character ch in infix:
        if ch is an operand:
            append ch to result
        else if ch is ')':
            push ch to stack
        else if ch is '(':
            while stack is not empty and top of stack is not ')':
                append top of stack to result
                pop from stack
            pop from stack
        else if ch is an operator:
            while stack is not empty and precedence(stack.top) >= precedence(ch):
                append top of stack to result
                pop from stack
            push ch to stack
    
    while stack is not empty:
        append top of stack to result
        pop from stack

    reverse(result)
    return result
```

# 2. Infix to Postfix Conversion
### Algorithm

* Initialize an empty stack for operators and an empty result string.
* Iterate over each character in the infix expression:
    * If the character is an operand, add it to the result string.
    * If the character is an operator, pop operators from the stack to the result string until an operator with less precedence is at the top or the stack is empty, then push the current operator onto the stack.
    * If the character is `(`, push it onto the stack.
    * If the character is `)`, pop from the stack to the result string until `(` is encountered.
* Pop any remaining operators from the stack to the result string.

### Dry Run Example

**Infix Expression** : `(A+B)*C-(D/E)`

1. Stack: ( -> Result: ``
1. Stack: (+ -> Result: `A`
1. Stack: (* -> Result: `AB+`
1. Stack: (- -> Result: `AB+C*`
1. Stack: / -> Result: `AB+C*DE/`
1. Pop all from the stack to get: `AB+C*DE/-`

### Pseudocode
```cpp
function infixToPostfix(infix):
    stack = empty stack
    result = empty string
    
    for each character ch in infix:
        if ch is an operand:
            append ch to result
        else if ch is '(':
            push ch to stack
        else if ch is ')':
            while stack is not empty and top of stack is not '(':
                append top of stack to result
                pop from stack
            pop from stack
        else if ch is an operator:
            while stack is not empty and precedence(stack.top) >= precedence(ch):
                append top of stack to result
                pop from stack
            push ch to stack
    
    while stack is not empty:
        append top of stack to result
        pop from stack
    
    return result
```