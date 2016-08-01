/*
 File: gene.h
*/

//length_gene(dna) returns the length of the first gene in
//   dna, or 0 if there is no gene in dna
//requires: dna != NULL
int length_gene(const char dna[]);

//extract_gene(dna, gene) finds the first gene in dna and 
//   puts it into the gene array given as a paremter
//requires: there is a valid gene (valid meaning at least one
//   codon between start and stop) in dna
//effects: mutates gene
void extract_gene(const char dna[], char gene[]);

//total_genes(dna) returns the total number of genes in dna, 
//   or 0 if there are no genes
//requires: dna != NULL
int total_genes(const char dna[]);

//reverse_complement(dna) changes dna into its reverse 
//   complement (reverses dna string and does base-pairing)
//requires: dna != NULL
//effects: mutates dna
void reverse_complement(char dna[]);