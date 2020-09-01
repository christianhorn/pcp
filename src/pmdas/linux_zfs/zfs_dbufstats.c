#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#include "zfs_dbufstats.h"

void
zfs_dbufstats_refresh(zfs_dbufstats_t *dbufstats, regex_t *rgx_row)
{
        int len_mn, len_mv;
	size_t nmatch = 3;
        regmatch_t pmatch[3];
        char *line, *mname, *mval;
	char *fname = "/proc/spl/kstat/zfs/dbufstats";
	FILE *fp;
        size_t len = 0;

        fp = fopen(fname, "r");
	if (fp != NULL) {
		while (getline(&line, &len, fp) != -1) {
                        if (regexec(rgx_row, line, nmatch, pmatch, 0) == 0) {
                                len_mn = pmatch[1].rm_eo - pmatch[1].rm_so;
                                len_mv = pmatch[2].rm_eo - pmatch[2].rm_so;
                                mname = (char *) malloc((size_t) (len_mn + 1) * sizeof(char));
                                mval  = (char *) malloc((size_t) (len_mv + 1) * sizeof(char));
                                strncpy(mname, line + pmatch[1].rm_so, len_mn);
                                strncpy(mval,  line + pmatch[2].rm_so, len_mv);
                                mname[len_mn] = '\0';
                                mval[len_mv] = '\0';

				if (strcmp(mname, "cache_count") == 0) dbufstats->cache_count = atoi(mval);
				else if (strcmp(mname, "cache_size_bytes") == 0) dbufstats->cache_size_bytes = atoi(mval);
				else if (strcmp(mname, "cache_size_bytes_max") == 0) dbufstats->cache_size_bytes_max = atoi(mval);
				else if (strcmp(mname, "cache_target_bytes") == 0) dbufstats->cache_target_bytes = atoi(mval);
				else if (strcmp(mname, "cache_lowater_bytes") == 0) dbufstats->cache_lowater_bytes = atoi(mval);
				else if (strcmp(mname, "cache_hiwater_bytes") == 0) dbufstats->cache_hiwater_bytes = atoi(mval);
				else if (strcmp(mname, "cache_total_evicts") == 0) dbufstats->cache_total_evicts = atoi(mval);
				else if (strcmp(mname, "cache_level_0") == 0) dbufstats->cache_level_0 = atoi(mval);
				else if (strcmp(mname, "cache_level_1") == 0) dbufstats->cache_level_1 = atoi(mval);
				else if (strcmp(mname, "cache_level_2") == 0) dbufstats->cache_level_2 = atoi(mval);
				else if (strcmp(mname, "cache_level_3") == 0) dbufstats->cache_level_3 = atoi(mval);
				else if (strcmp(mname, "cache_level_4") == 0) dbufstats->cache_level_4 = atoi(mval);
				else if (strcmp(mname, "cache_level_5") == 0) dbufstats->cache_level_5 = atoi(mval);
				else if (strcmp(mname, "cache_level_6") == 0) dbufstats->cache_level_6 = atoi(mval);
				else if (strcmp(mname, "cache_level_7") == 0) dbufstats->cache_level_7 = atoi(mval);
				else if (strcmp(mname, "cache_level_8") == 0) dbufstats->cache_level_8 = atoi(mval);
				else if (strcmp(mname, "cache_level_9") == 0) dbufstats->cache_level_9 = atoi(mval);
				else if (strcmp(mname, "cache_level_10") == 0) dbufstats->cache_level_10 = atoi(mval);
				else if (strcmp(mname, "cache_level_11") == 0) dbufstats->cache_level_11 = atoi(mval);
				else if (strcmp(mname, "cache_level_0_bytes") == 0) dbufstats->cache_level_0_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_1_bytes") == 0) dbufstats->cache_level_1_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_2_bytes") == 0) dbufstats->cache_level_2_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_3_bytes") == 0) dbufstats->cache_level_3_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_4_bytes") == 0) dbufstats->cache_level_4_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_5_bytes") == 0) dbufstats->cache_level_5_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_6_bytes") == 0) dbufstats->cache_level_6_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_7_bytes") == 0) dbufstats->cache_level_7_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_8_bytes") == 0) dbufstats->cache_level_8_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_9_bytes") == 0) dbufstats->cache_level_9_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_10_bytes") == 0) dbufstats->cache_level_10_bytes = atoi(mval);
				else if (strcmp(mname, "cache_level_11_bytes") == 0) dbufstats->cache_level_11_bytes = atoi(mval);
				else if (strcmp(mname, "hash_hits") == 0) dbufstats->hash_hits = atoi(mval);
				else if (strcmp(mname, "hash_misses") == 0) dbufstats->hash_misses = atoi(mval);
				else if (strcmp(mname, "hash_collisions") == 0) dbufstats->hash_collisions = atoi(mval);
				else if (strcmp(mname, "hash_elements") == 0) dbufstats->hash_elements = atoi(mval);
				else if (strcmp(mname, "hash_elements_max") == 0) dbufstats->hash_elements_max = atoi(mval);
				else if (strcmp(mname, "hash_chains") == 0) dbufstats->hash_chains = atoi(mval);
				else if (strcmp(mname, "hash_chain_max") == 0) dbufstats->hash_chain_max = atoi(mval);
				else if (strcmp(mname, "hash_insert_race") == 0) dbufstats->hash_insert_race = atoi(mval);
				else if (strcmp(mname, "metadata_cache_count") == 0) dbufstats->metadata_cache_count = atoi(mval);
				else if (strcmp(mname, "metadata_cache_size_bytes") == 0) dbufstats->metadata_cache_size_bytes = atoi(mval);
				else if (strcmp(mname, "metadata_cache_size_bytes_max") == 0) dbufstats->metadata_cache_size_bytes_max = atoi(mval);
				else if (strcmp(mname, "metadata_cache_overflow") == 0) dbufstats->metadata_cache_overflow = atoi(mval);
                                free(mname);
                                free(mval);
                        }
                }
        }
        fclose(fp);
}
