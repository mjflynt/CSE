
(define char_toupper (lambda (achar)
                       (if (not (or (char<? achar #\a) (char>? achar #\z)))
                           (integer->char (- (char->integer achar) (- (char->integer #\a) (char->integer #\A))))
                           achar
                           )
                       )
  )

(define string_toupper (lambda (astring)
                         (if (> (string-length astring) 0)
                             (string-append (string (char_toupper (string-ref astring 0))) (string_toupper (substring astring 1 (string-length astring))))
                             ""
                             ) 
                         )
  )

(display (string_toupper (read-line))) 

