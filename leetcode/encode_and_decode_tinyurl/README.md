## Brief Description

### base62_two_maps.cpp

* Maintain two `unordered_map`s, one to map indices of the original URLs to base-62 encodings and the other to map vice versa.
	* The base-62 encoding represents each of the values using one of the symbols from a set [0-9A-Za-z].
* `decimalToBase62`:
	* Convert the decimal number `decimal` to the base-62 representation symbol by symbol, just as we convert the numbers from decimal to binary. Use the ASCII table.
	* Push to a stack each symbol from the last one, push `'0'` until the stack has `NUM_SYMBOLS` items, and then return the entire base-62 encoding in correct order.
* `encode`:
	* If the key `longUrl` is found in `orig_to_base62`, assign the value of it to `base62`.
	* Otherwise, convert the index of `longUrl` (i.e., `orig_to_base62.size()`) to a base-62 format using `decimalToBase62`, assign it to `base62`, and populate the pair of `unordered_map`s.
	* Return `base62` with `domain`.
* `decode`:
	* If the key `base62`, which is `shortUrl` with its `domain` part stripped away, is found in `base62_to_orig`, assign the value of it to `orig`.
	* Return `orig`. (If the key `base62` has not been found, it remains as an empty string in this code.)