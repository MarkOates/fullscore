#(define (override-color-for-all-grobs color)
  (lambda (context)
   (let loop ((x all-grob-descriptions))
    (if (not (null? x))
     (let ((grob-name (caar x)))
      (ly:context-pushpop-property context grob-name 'color color)
      (loop (cdr x)))))))

<<
  % This section adds an \applyContext to set the grob color to white, and
  % includes teh code snippet at the top of the file.  This technique was
  % taken from http://lsr.di.unimi.it/LSR/Snippet?id=443
  \applyContext #(override-color-for-all-grobs (x11-color 'white))
  \new Staff
  {
    %%%INSERT_STAFF_CONTENTS_HERE%%%

    % This section sets the background to near-black, by drawing a large box
    % over the score.  This technique was taken from:
    % http://lsr.di.unimi.it/LSR/Snippet?id=699
    -\tweak layer #-1
    -\markup {
      \with-dimensions #'(0 . 0) #'(0 . 0)
      % specify color
      \with-color #(rgb-color 0.05 0.05 0.05)
      % specify size
      \filled-box #'(-1000 . 1000) #'(-1000 . 4000) #0
    }
  }
  %%%INSERT_ADDITIONAL_STAVES_HERE%%%
>>

\version "2.18.2"  % necessary for upgrading to future LilyPond versions.

