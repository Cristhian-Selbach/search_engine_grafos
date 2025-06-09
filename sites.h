#ifndef SITES_H
#define SITES_H

#define MAX_SITES 50
#define MAX_URL 50
#define MAX_DESC 2000
#define MAX_TITULO 100

typedef struct {
    char url[MAX_URL];
    char titulo[MAX_TITULO];
    char descricao[MAX_DESC];
} Site;

extern Site sites[MAX_SITES];
extern int totalSites;

#endif
