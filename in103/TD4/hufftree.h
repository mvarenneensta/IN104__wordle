#ifndef __HUFFTREE_H__
#define __HUFFTREE_H__

struct huff_node_t{
	char letter;
	int  num_occs;
	struct huff_node_t *left;
	struct huff_node_t *right;
}
#endif
