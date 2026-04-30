・std::ostream &operator<<(std::ostream &out, const Form &form) 引数には、ostreamがあるのに、呼び出しではこの第一引数を使っていないのはなぜか？
->　コンパイラがstd::cout << form;これをoperator<<(std::cout, form);という関数呼び出しに変更するから。
戻り値が参照なのは、連続して演算子を仕様したときの次の演算子の第一引数に仕様するため。
