
(define (find_min x)
  (if (not (symbol? x))
      (begin
        (define readval (read))
        (if (= readval 0)
            (if (< 0 x)
                0
                x
                )
            (if (< readval x)
                (find_min readval)
                (find_min x)
                )
            ))
      ((define readval (read))
       (if (= readval 0)
           0
           (find_min readval)
           ))
      )
  )
      
(find_min 'start)