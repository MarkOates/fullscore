#(define (override-color-for-all-grobs color)
  (lambda (context)
   (let loop ((x all-grob-descriptions))
    (if (not (null? x))
     (let ((grob-name (caar x)))
      (ly:context-pushpop-property context grob-name 'color color)
      (loop (cdr x)))))))

\score {
  <<
    % This section adds an \applyContext to set the grob color to white, and
    % includes teh code snippet at the top of the file.  This technique was
    % taken from http://lsr.di.unimi.it/LSR/Snippet?id=443
    \applyContext #(override-color-for-all-grobs (x11-color 'white))
    %%%INSERT_ADDITIONAL_STAVES_HERE%%%
  >>
  \layout {
    \context {
      \Score
      \override SpacingSpanner.base-shortest-duration = #(ly:make-moment 1/16)
    }
  }
}

\version "2.18.2"  % necessary for upgrading to future LilyPond versions.

