public class ValidOutput {
    public static String calculateOutput(String formatFrom, String formatTo, String numberIn) {
        switch (formatFrom) {
            case "0":
                if (formatTo.equals("0")) {
                    return numberIn;
                }
                if (formatTo.equals("1")) {
                    return reverseString(decimalToHex(Integer.parseInt(numberIn), ""));
                }
                if (formatTo.equals("2")) {
                    return reverseString(decimalToBinary(Integer.parseInt(numberIn), ""));
                }
                break;
            case "1":
                if (formatTo.equals("0")) {
                    return hexToDecimal(numberIn);
                }
                if (formatTo.equals("1")) {
                    return numberIn;
                }
                if (formatTo.equals("2")) {
                    return reverseString(hexToBinary(numberIn));
                }
                break;
            case "2":
                if (formatTo.equals("0")) {
                    return binaryToDecimal(numberIn);
                }
                if (formatTo.equals("1")) {
                    return binaryToHex(numberIn);
                }
                if (formatTo.equals("2")) {
                    return numberIn;
                }
                break;
        }

        return "";
    }

    public static String reverseString(String str) {
        String reverse = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reverse += str.charAt(i);
        }
        return reverse;
    }

    public static String convertHexToDec(String str) {
        switch (str) {
            case "A":
                return "10";
            case "B":
                return "11";
            case "C":
                return "12";
            case "D":
                return "13";
            case "E":
                return "14";
            case "F":
                return "15";
            default:
                return str;
        }
    }

    public static String convertDecToHex(int num) {
        switch (num) {
            case 10:
                return "A";
            case 11:
                return "B";
            case 12:
                return "C";
            case 13:
                return "D";
            case 14:
                return "E";
            case 15:
                return "F";
            default:
                return Integer.toString(num);
        }
    }

    public static String decimalToHex(int num, String bit) {
        int q = num / 16;
        int r = num - q * 16;
        String res = convertDecToHex(r);
        String b = bit += res;
        if (q > 0) {
            return decimalToHex(q, bit);
        }
        return b;
    }

    public static String decimalToBinary(int num, String bit) {
        int q = num / 2;
        int r = num - q * 2;
        String b = bit += r;
        if (q > 0) {
            return decimalToBinary(q, bit);
        }
        return b;
    }

    public static String hexToDecimal(String str) {
        str = str.toUpperCase();
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            String s = convertHexToDec(Character.toString(str.charAt(i)));
            int pow = (int) Math.pow(16, str.length() - i - 1);
            res += Integer.parseInt(s) * pow;
        }
        return Integer.toString(res);
    }

    public static String hexToBinary(String str) {
        return decimalToBinary(Integer.parseInt(hexToDecimal(str)), "");
    }

    public static String binaryToDecimal(String str) {
        char[] arr = str.toCharArray();
        int res = 0;
        for (int i = 0; i < arr.length; i++) {
            res += (arr[i] - '0') * Math.pow(2, arr.length - i - 1);
        }
        return Integer.toString(res);
    }

    public static String binaryToHex(String str) {
        int missingZeros = (4 - (str.length() % 4)) % 4;
        for (int i = 0; i < missingZeros; i++) {
            str = "0" + str;
        }

        int numChunks = str.length() / 4;
        String[] chunks = new String[numChunks];
        for (int i = 0; i < numChunks; i++) {
            chunks[i] = str.substring(i * 4, (i + 1) * 4);
        }

        String res = "";
        int[] sum = new int[numChunks];
        for (int i = 0; i < chunks.length; i++) {
            for (int j = 0; j < 4; j++) {
                sum[i] += (chunks[i].charAt(j) - '0') * Math.pow(2, 3 - j);
            }
        }
        for (int i = 0; i < sum.length; i++) {
            res += convertDecToHex(sum[i]);
        }
        return res;
    }
}
