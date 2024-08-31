| Step | Character | Action                                   | Stack `st` | Postfix  |
|------|-----------|------------------------------------------|------------|----------|
| 1    | `(`       | Push to stack                            | `(`        |          |
| 2    | `x`       | Append to postfix                        | `(`        | `x`      |
| 3    | `+`       | Push to stack (it's an operator)         | `(+`       | `x`      |
| 4    | `y`       | Append to postfix                        | `(+`       | `xy`     |
| 5    | `*`       | Push to stack (higher precedence)        | `(+*`      | `xy`     |
| 6    | `z`       | Append to postfix                        | `(+*`      | `xyz`    |
| 7    | `/`       | Pop `*` (higher or equal precedence)     | `(+/`      | `xyz*`   |
| 8    | `w`       | Append to postfix                        | `(+/`      | `xyz*w`  |
| 9    | `+`       | Pop `/` (higher precedence)              | `(+`       | `xyz*w/` |
| 10   | `+`       | Push `+` (equal precedence as `+`)       | `(++`      | `xyz*w/` |
| 11   | `u`       | Append to postfix                        | `(++`      | `xyz*w/u`|
| 12   | `)`       | Pop until `(` is found                   | `(`        | `xyz*w/u+`|
| 13   | End       | Pop the remaining `(`                    | Empty      | `xyz*w/u+`|
