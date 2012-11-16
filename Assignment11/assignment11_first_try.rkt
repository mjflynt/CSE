(define inputlist '())

(define getinput (lambda ()
                   (begin
                     (set! inputlist (append (list (read)) inputlist))
                     (if (= (car inputlist) 0)
                         inputlist
                         (getinput)
                         )
                     )
                   )
  )

(define find_min (lambda (x min)
                   (if (null? (cdr x))
                              min
                              (if (< (car x) min)
                                  (find_min (cdr x) (car x))
                                  (find_min (cdr x) min)
                                  )
                              )
                   )
  )
                               
(find_min (getinput) 999999)

                   
                        

                        
  