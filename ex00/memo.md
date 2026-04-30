# クラス内のstaticメンバ関数
- thisポインタを持たない
- staticメンバ変数にしかアクセスできない
- オブジェクトなしで呼べる

# throw()について
- throw　A;のthrow
ex:throw GradeTooHighException();
Aという例外を投げるためのthrow

- 関数宣言の後ろにあるthrow
ex:virtual const char* what() const throw();
宣言した関数が例外を投げないことを明示するためのthrow;
