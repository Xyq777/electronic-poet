#ifndef UTIL_H
#define UTIL_H

/**
 * @brief 退出程序。
 */
extern void End_program();

/**
 * @brief 扫描一行诗句。
 * @return 扫描到的字符数。
 */
extern int Scan_line_of_poem();

/**
 * @brief 扫描一段诗句。
 * @return 扫描到的字符数。
 */
extern int Scan_paragraph_of_poem();

/**
 * @brief 扫描诗歌的名称。
 * @return 诗歌的名称。
 */
extern char* Scan_name_of_poem();

#endif  // UTIL_H