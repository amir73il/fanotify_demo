#ifndef _ITER_H
#define _ITER_H

extern int tree_depth;
extern int tree_width;
extern int leaf_start;
extern int leaf_count;
extern int node_count;
extern char *file_prefix;
extern char *dir_prefix;
extern int data_seed;
extern int keep_data;
extern int copy_root_acls;
extern int copy_root_mtime;

void iter_usage();
int iter_parseopt(int argc, char *argv[]);

typedef long long int xid_t;

#define XATTR_XID "user.iter.xid"

/*
 * hex xid needs to fit into a fixed size string including the
 * block offset, sperator char and terminating null, e.g.: "1000/3"
 */
#define XID_MAX_HEX_LEN 10
#define BLOCKS_PER_MB 1

extern int file_blocks;

typedef int (*iter_op)(const char *, int, xid_t);

int iter_tree(iter_op op, int depth);
#endif
