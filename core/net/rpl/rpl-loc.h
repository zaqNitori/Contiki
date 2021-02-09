#ifndef RPL_LOC_H
#define RPL_LOC_H

typedef struct rpl_loc{
int fpx;		// f => front point
int bpx;		// b => behind point
int fpy;
int bpy;
char isfix;	//1 => server, 0 => client 
}rpl_loc_t;
#endif
