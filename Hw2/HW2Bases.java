/**
 * CS 2110 Fall 2016 HW2 Part 2 - Coding with bases
 *
 * @author Aatmay S. Talati
 *
 *         Global rules for this file: - You may not use more than 2
 *         conditionals per method. Conditionals are if-statements, if-else
 *         statements, or ternary expressions. The else block associated with an
 *         if-statement does not count toward this sum. - You may not use more
 *         than 2 looping constructs per method. Looping constructs include for
 *         loops, while loops and do-while loops. - You may not use nested
 *         loops. - You may not declare any file-level variables. - You may not
 *         declare any objects, other than String in select methods. - You may
 *         not use switch statements. - You may not use the unsigned right shift
 *         operator (>>>) - You may not write any helper methods, or call any
 *         other method from this or another file to implement any method. - The
 *         only Java API methods you are allowed to invoke are: String.length()
 *         String.charAt() String.equals() - You may not invoke the above
 *         methods from string literals. Example: "12345".length() - When
 *         concatenating numbers with Strings, you may only do so if the number
 *         is a single digit.
 *
 *         Method-specific rules for this file: - You may not use
 *         multiplication, division or modulus in any method, EXCEPT strdtoi. -
 *         You may declare exactly one String variable each in itostrb, and
 *         itostrx.
 */
public class HW2Bases {
	/**
	 * strbtoi - Binary String to int
	 *
	 * Convert a string containing ASCII characters (in binary) to an int. You
	 * do not need to handle negative numbers. The Strings we will pass in will
	 * be valid binary numbers, and able to fit in a 32-bit signed integer.
	 *
	 * Example: strbtoi("111"); // => 7
	 */
	public static int strbtoi(String binary) {
		// TODO implement this method
		int bin_result = 0;
		int bin_intNumber = 0;
		// int j =0;
		int bin_base = 1;

		for (int j = binary.length(); j > 0; j--) {
			if (binary.charAt(j - 1) - 48 == 1) {
				bin_result = bin_result + bin_base;
			}

			// Multipliication is banned bin_base = bin_base * 2;
			bin_base = bin_base + bin_base;
		}

		return bin_result;

	}

	/**
	 * strdtoi - Decimal String to int
	 *
	 * Convert a string containing ASCII characters (in decimal) to an int. You
	 * do not need to handle negative numbers. The Strings we will pass in will
	 * be valid decimal numbers, and able to fit in a 32-bit signed integer.
	 *
	 * Example: strdtoi("123"); // => 123
	 */
	public static int strdtoi(String decimal) {
		int dec_result = 0;
		int dec_intNumber = 0;
		int i = 0;
		int dec_base = 1;

		for (i = decimal.length() - 1; i >= 0; i--) {

			dec_intNumber = decimal.charAt(i) - 48; // ASCII VALUE OF 0 IS 48
			dec_result = dec_result + (dec_intNumber * dec_base);
			dec_base = dec_base * 10;
		}

		return dec_result;

	}

	/**
	 * strxtoi - Hexadecimal String to int
	 *
	 * Convert a string containing ASCII characters (in hex) to an int. The
	 * input string will only contain numbers and uppercase letters A-F. You do
	 * not need to handle negative numbers. The Strings we will pass in will be
	 * valid hexadecimal numbers, and able to fit in a 32-bit signed integer.
	 *
	 * Example: strxtoi("A6"); // => 166
	 */
	public static int strxtoi(String hex) {
		int hex_result = 0;
		int hex_temp = 0;

		for (int i = hex.length() - 1; i >= 0; i--) {
			// char randomChar = hex.charAt(i);
			int hex_y = 0;

			if (hex.charAt(i) == 'A' || hex.charAt(i) == 'B' || hex.charAt(i) == 'C' || hex.charAt(i) == 'D'
					|| hex.charAt(i) == 'E' || hex.charAt(i) == 'F') {
				hex_y = hex.charAt(i) - 55; // A is 65. So if we deduct 55 then
											// we can get 10
			} else {
				hex_y = hex.charAt(i) - 48;
			}

			hex_result = hex_result + (hex_y << hex_temp);
			hex_temp = hex_temp + 4;
		}

		return hex_result;

	}

	/**
	 * itostrb - int to Binary String
	 *
	 * Convert a int into a String containing ASCII characters (in binary). You
	 * do not need to handle negative numbers. The String returned should
	 * contain the minimum number of characters necessary to represent the
	 * number that was passed in.
	 *
	 * Example: itostrb(7); // => "111"
	 */
	public static String itostrb(int binary) {
		String strb_result = "";
		int strb_intvar = 0;
		int strb_ekam = 1;
		strb_intvar = 1;

		if (binary == 0) {
			return "0";
			// return strb_result;
		}

		else {

			while (binary != 0) {
				int while_loop_var;
				while_loop_var = binary & 1;
				binary = binary >> strb_ekam;

				if (strb_ekam == 1) {
					strb_result = "1" + strb_result;
				}

				else {
					strb_result = "0" + strb_result;
				}
			}
		}

		return strb_result;
	}

	/**
	 * itostrx - int to Hexadecimal String
	 *
	 * Convert a int into a String containing ASCII characters (in hexadecimal).
	 * The output string should only contain numbers and uppercase letters A-F.
	 * You do not need to handle negative numbers. The String returned should
	 * contain the minimum number of characters necessary to represent the
	 * number that was passed in.
	 *
	 * Example: itostrx(166); // => "A6"
	 */
	public static String itostrx(int hex) {
		String hex_result = "";
		if (hex == 0) {
			return "0";
		}

		else {
			
			while (hex != 0) {

				int while_loop_var = hex >> 4;
				int while_loop_var2 = hex - (while_loop_var << 4);

				if (while_loop_var2 < 10) {
					hex_result = (char) (while_loop_var2 + 48) + hex_result;
				}

				else if (while_loop_var2 >= 10) {
					hex_result = (char) (while_loop_var2 + 55) + hex_result;
				}
			}
		}

		return hex_result;

	}

}
