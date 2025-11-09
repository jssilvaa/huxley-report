# Huxley — Embedded Communications System (Report)

LaTeX report for the Huxley - Embedded Communications System course unit project.

## Contents
- LaTeX source for the course project report (main .tex file in the repo root or a subfolder).
- Small C++ snippets/tools used with the report (if any) in a separate folder.

## Prerequisites
- TeX distribution (TeX Live, MacTeX, or MiKTeX) with usual packages.
- latexmk is recommended for simple, repeatable builds.
- If the report uses bibtex or biber, have the corresponding tool installed.

## Recommended (one-line) build
Replace report.tex below with the actual main .tex filename (e.g., main.tex, report.tex)
- Chose between main.tex or presentation.tex
- You can select what modules to include in the main.tex file.

latexmk -pdf -interaction=nonstopmode -file-line-error report.tex

This runs the full workflow (multiple passes, bibtex/biber if needed) and produces report.pdf.

## Manual build (if not using latexmk)
1. Run pdflatex:
   pdflatex report.tex
2. If you use BibTeX:
   bibtex report
   If you use biber:
   biber report
3. Run pdflatex two more times:
   pdflatex report.tex
   pdflatex report.tex

## Clean build artifacts
- With latexmk:
  latexmk -c
- Or manually remove auxiliary files:
  rm -f *.aux *.log *.bbl *.blg *.toc *.out *.fls *.fdb_latexmk

## Overleaf
You can upload the project folder to Overleaf and compile there if you prefer a web-based editor.

## Troubleshooting
- Missing packages: install the package via tlmgr (TeX Live) or install the full TeX distribution.
- If compilation fails, inspect the .log file or run pdflatex with -file-line-error for clearer messages.
- If bibliography doesn't show: ensure you ran bibtex or biber and then pdflatex twice.
