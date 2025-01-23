all: feynman.pdf

feynman.pdf: feynman.tex references.bib
	pdflatex --shell-escape feynman.tex
	bibtex feynman
	mpost annihilation1.mp
	mpost annihilation2.mp
	pdflatex --shell-escape feynman.tex
	pdflatex --shell-escape feynman.tex

clean:
	rm -f *.aux *.log *.bbl *.blg *.fdb_latexmk *.fls *.synctex.gz *.out *.mp *.mps

