#ifndef __API_LEVEL_H__
#define __API_LEVEL_H__
/**
 * Get the most preferable sdk level for current android.
 * I.E. Android 4.4 should use the lib end with xxx_sdk19.so
 */
int get_most_preferrable_level();
#endif //__API_LEVEL_H__
