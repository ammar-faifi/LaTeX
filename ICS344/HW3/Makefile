# Makefile for compiling LaTeX documents

# Set the main LaTeX file (without the .tex extension)
MAIN_FILE = main

# Set the LaTeX compiler
LATEX_COMPILER = pdflatex

# Set additional flags for the LaTeX compiler if needed
LATEX_FLAGS = -shell-escape -interaction=nonstopmode

# Set the target PDF file
TARGET = $(MAIN_FILE).pdf

all: $(TARGET)

$(TARGET): $(MAIN_FILE).tex
	$(LATEX_COMPILER) $(LATEX_FLAGS) $(MAIN_FILE).tex

clean:
	rm -f *.aux *.log *.out *.toc *.bbl *.blg *.lot *.lof

.PHONY: all clean
