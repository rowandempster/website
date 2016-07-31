#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "gene.h"
#include <stdbool.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Rowan Dempster
// login ID: R2DEMPST

// implementation:

//string buffer for split function
char dna_buffer[1000];

//start and stop flags for genes
const char start[] = "ATG";
const char end1[] = "TAG";
const char end2[] = "TAA";
const char end3[] = "TGA";

//Length of a codon
const int len_of_codon = 3;

//codon_type(codon) returns the "type" of codon, 1 for an 
//   "end" type (TAG, TTA, or TGA), -1 for "start" type
//   (ATG), or 0 if neither start nor end type
//requires: codon != NULL
static int codon_type(const char codon[]){
  assert(codon);
  if((strcmp(codon, end1) == 0) || 
     (strcmp(codon, end2) == 0) || 
     (strcmp(codon, end3) == 0)){
    return 1;
  }
  if(strcmp(codon, start) == 0){
    return -1; 
  }
  return 0;
}

//split(result, dna) splits the long string of dna chars into
//   their individual Codons (stored as strings), and places
//   the pointers to those codon strings in result
//   requires: len(result)>len(dna)/3, so that result can 
//   store all of the codon pointers
//   Also, len(dna) < 900, in order to use the dna_buffer I 
//   set up
//   effects: mutates result
static void split(char *result[], const char dna[]){
  assert(result&&dna);
  int dna_counter = 0;
  int buff_counter = 0;
  //set up buffer
  while(dna[dna_counter]){
    //place null terminater after each len 3 codon
    if((buff_counter%(len_of_codon+1)) == len_of_codon){
      dna_buffer[buff_counter] = 0; 
      buff_counter++;
    }
    //else just keep placing dna if not at end of codon
    else{
      dna_buffer[buff_counter] = dna[dna_counter];
      buff_counter++;
      dna_counter++;
    }
  }
  //assign codon pointers in the buffer to the codon array
  int buffer_len = strlen(dna) + strlen(dna)/3;
  int result_index_counter = 0;
  for(int i = 0; i<buffer_len; i++){
    if(dna_buffer[i] == 0){
      result[result_index_counter] = &dna_buffer[i-3];
      result_index_counter++;
    }
  }
}

//no_begin(codons, len) returns the index of the first start
//   codon in codons, or -1 if there is no start
//requires: len is the number of codons
static int no_begin(char* codons[], int len){
 for(int i = 0; i<len; i++){
  if(codon_type(codons[i]) == -1){
   return i; 
  }
 }
  return -1;
}

//no_end(codons, len, start) returns false if it finds an end
//   codon after start, true otherwise
//requires: len is the length of codons and start<len
static bool no_end(char* codons[], int len, int start){
  for(int i = start; i<len; i++){
    if(codon_type(codons[i]) == 1){
      return false; 
    }
  }
  return true;
}

//see .h for descriptions
int length_gene(const char dna[]){
  assert(dna);
  //set up codon array
  int num_codons = strlen(dna)/len_of_codon;
  int begin = 0;
  char *codons[num_codons];
  split(codons, dna);
  //check if gene starts and if so get that start
  if((no_begin(codons, num_codons))==-1){
    return 0; 
  }
  else{
   begin = no_begin(codons, num_codons);
  }
  //check if gene ends after it starts
  if(no_end(codons, num_codons, begin)){
    return 0; 
  }
  int len = 0;
  //increment len until find the end of gene
  int i = begin+1;
  for(;codon_type(codons[i]) != 1; i++){
    len++; 
  }
  return len;
}


void extract_gene(const char dna[], char gene[]) {
  assert(dna&&gene);
  //set up codon array
  int num_codons = strlen(dna)/len_of_codon;
  char *codons[num_codons];
  split(codons, dna);
  //find beggining and end of gene in dna
  int begin_codon = no_begin(codons, num_codons);
  int begin_dna = begin_codon*len_of_codon;
  int end_dna = begin_dna+(length_gene(dna)+2)*len_of_codon;
  //put that found gene into given gene array
  int gene_counter = 0;
  for(;begin_dna<end_dna;begin_dna++){
    gene[gene_counter] = dna[begin_dna];
    gene_counter++;
  }
  //make that gene a string!
  gene[end_dna] = 0;
}

int total_genes(const char dna[]){
  assert(dna);
  //set up codon array
  int num_codons = strlen(dna)/len_of_codon;
  char *codons[num_codons];
  split(codons, dna);
  int curr_codon = 0;
  int gene_counter = 0;
  int in_gene = 0;
  while(curr_codon<num_codons) {
    //if we are in a gene, and we find an "end" type codon:
    //   increment the gene_counter, and keep going
    if(in_gene && codon_type(codons[curr_codon]) == 1) {
      curr_codon++;
      gene_counter++;
      in_gene = 0;
    }
    //if we aren't in a gene, and we find the beggining of 
    //   a gene: set in_gene to true and keep going
    else if(!in_gene&&codon_type(codons[curr_codon]) == -1) {
      curr_codon++;
      in_gene = 1;
    }
    //otherwise just keep going
    else{
      curr_codon++;
    }
  }
  return gene_counter;
}

//reverse_string(str) reverses the order of the chars in str
//requires: str != NULL
//effects: mutates str
void reverse_string(char str[]){
  assert(str);
  int first_half = strlen(str)/2;
  int end_index = strlen(str)-1;
  int i = 0;
  while(first_half>0){
    char temp = str[i];
    str[i] = str[end_index];
    str[end_index] = temp;
    i++;
    end_index--;
    first_half--;
  }
}

void reverse_complement(char dna[]){
  assert(dna);
  int len = strlen(dna);
  reverse_string(dna);
  for( int i = 0; i<len; i++){
    if(dna[i] == 'A'){
      dna[i] = 'T';
    }
    else if(dna[i] == 'T'){
      dna[i] = 'A';
    }
    else if(dna[i] == 'C'){
      dna[i] = 'G';
    }
    else{
      dna[i] = 'C';
    }
  }
}