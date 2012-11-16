


(define char_toupper (lambda (achar)
                       (if (not (or (char<? achar #\a) (char>? achar #\z)))
                           (integer->char (- (char->integer achar) (- (char->integer #\a) (char->integer #\A))))
                           achar
                           )
                       )
  )
                           

(char_toupper (read)) 