

(define class-size
            '(("CSE100" . 120) ("CSE110" . 140) ("CSE205" . 100) ("CSE240" . 80)  ("CSE310" . 70) ("CSE360" . 75) ("CSE420" . 65)))

(define big-class? (lambda (x) (>= (cdr x) 100)))

(display (filter big-class? class-size))
(newline)

(define food '( 
               ("Pecan" . (1982 .("nut". "AL"))) 
               ("Blackberry" . (2004 .("fruit". "AL")))  
               ("Peach" . (2006 .("fruit". "AL"))) 
               ("Rice" . (2007 .("grain". "AR"))) 
               ("Orange" . (2005 .("fruit". "FL"))) 
               ("Huckleberry" . (2000 .("fruit". "ID")))
               ("Blackberry" . (2004 .("fruit". "KY")))
               ("Strawberry" . (1980 .("fruit". "LA")))
               ("WildBlueberry" . (1991 .("fruit". "ME")))
               ("BlueCrab" . (2000 .("food". "MD")))
               ("HoneycrispApple" . (2006 .("fruit". "MN")))
               ("Pumpkin" . (2000 .("fruit". "NH")))
               ("Chile" . (1965 .("vegetable". "NM")))
               ("Blueberry" . (2001 .("fruit". "NC")))
               ("ChokeCherry" . (2007 .("fruit". "ND")))
               ("WaterMelon" . (2007 .("vegetable". "OK")))
               ("Pear" . (2000 .("fruit". "OR")))
               ("Hazelnut" . (2000 .("nut". "OR")))
               ("Peach" . (1984 .("fruit". "SC")))
               ("Tomato" . (2003 .("fruit". "TN")))
               ("Jalapeno" . (1995 .("vegetable". "TX")))
               ("Apple" . (2000 .("fruit". "WA")))         
  ))  

(define vegetable? (lambda (x) (string=? "vegetable" (caddr x))))

(define blackberry? (lambda (x) (string=? "Blackberry" (car x))))

(define oregon? (lambda (x) (string=? "OR" (cdddr x))))

 

(display (filter vegetable? food))
(newline)
(newline)

(display (filter blackberry? food))
(newline)
(newline)

(display (filter oregon? food))
(newline)
(newline)


 
