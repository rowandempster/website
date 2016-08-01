
//Simple test of gene module

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "gene.h"



int main(void){
  //test length_gene
  char dna[] ="AGTCATATGCATCTTGGGCAAATGTGA";
  printf("length is: %d\n", length_gene(dna));

  //test extract_gene
  char gene[28];
  extract_gene(dna,gene);
  printf("gene: %s\n",gene);

  //test total_genes
  char dna2[] ="ATGCATTGACGCATGGGGTGA";
  printf("total: %d\n",total_genes(dna2)); 

  //test reverse_complement
  char dna3[] ="ATGCAT";
  reverse_complement(dna3);
  printf("reverse_c: %s\n",dna3); 

  char my_dna[] ="CTGACTTACCTGATGCATTCCATGCTAGTACGATAAGTAATGCCAAACTGAATGGACATGCCATAG";
  printf("length is: %d\n", length_gene(my_dna));

  //test extract_gene
  char my_gene[50];
  extract_gene(my_dna,my_gene);
  printf("gene: %s\n", my_gene);

  //test total_genes
  printf("total: %d\n",total_genes(my_dna)); 

  char no_gene[] ="GTATGAGTAATCCCCACT";
  printf("length is: %d\n", length_gene(no_gene));
  printf("total: %d\n", total_genes(no_gene)); 

  char empty[] = "";
  printf("length is: %d\n", length_gene(empty));
  char atg[] = "ATGATGATGATGATG";
  printf("length is: %d\n", length_gene(atg));
  printf("length is: %d\n", length_gene("CTGATCTAATAGATGCTG"));
  printf("length is: %d\n", length_gene("CTGATCTAATAGATG"));
  printf("length is: %d\n", length_gene("CTGATGCTGATCATG"));
  printf("length is: %d\n", length_gene("ATGTCGATGATGATGTAGATGATGCGTATG"));


  extract_gene("ATGTCGATGATGATGTAGATGATGCGTATG",my_gene);
  printf("gene: %s\n", my_gene);
  printf("length is: %d\n", length_gene("CGATAGTAAATGATGTAGATGATGCTATAG"));
  char my_gene_2[31]; 
  extract_gene("CGATAGTAAATGATGTAGATGATGCTATAG",my_gene_2);
  printf("gene: %s\n", my_gene_2);
  char my_gene_3[40]; 
  extract_gene("TAGTAACGTATGCTAATGATGCGTTAGATCATGCTGTAG",my_gene_3);
  printf("gene: %s\n", my_gene_3);

  printf("total: %d\n",total_genes("ATGATGTAGTAGTAGATGCTATAGATG")); 
    printf("total: %d\n",total_genes("CTATAGATGATGTAGATGCTGTAGTAGTAGATGCTAATGTAGTAGCTAGATATGCTAATGCGAATGTAGATCATGACGATG")); 
    printf("total: %d\n",total_genes("ATG")); 
  printf("total: %d\n",total_genes("ATGATG"));
  printf("total: %d\n",total_genes("ATGATGTAGATG"));
  printf("total: %d\n",total_genes("CTATAG"));
  printf("total: %d\n",total_genes("CTAATGCTA"));
  printf("total: %d\n",total_genes("CCCATGCCCAAATAG"));
  printf("total: %d\n",total_genes("CATGCCCAAATAGCCATGCTGTAA "));
  printf("total: %d\n",total_genes("CCCCCCTGACCCATGCCCAAATAGCCC"));
    printf("total: %d\n",total_genes("ATGCCCAAATAGCCATGTGATAGCATGCCCAAATAGCCC"));



}



