using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace json_validator
{
    public class Lexer
    {
        public int Accumulator { get; set; }
        public char? Current_char { get; set; }
        public string Text { get; set; }

        public Lexer(in string json_input)
        {
            Accumulator = 0;
            Text = json_input;
            Current_char = Text[Accumulator];
        }

        private void Advance()
        {
            try
            {
                Current_char = Text[++Accumulator];
            }
            catch (Exception)
            {
                Current_char = null;
            }
        }

        private double Make_number()
        {
            return 0.0;
        }

        public List<Token> generate_tokens()
        {
            var token_list = new List<Token>();
            Regex re = new(
                pattern:
                    "/[^\"\n\r\\]*/",
                options:
                    RegexOptions.Compiled |
                    RegexOptions.IgnoreCase |
                    RegexOptions.IgnorePatternWhitespace
            );

            while (Current_char != null)
            {
                if (Commun_values.WHITESPACE.Contains((char)Current_char))
                    token_list.Add(new Token(
                        TokenTypeName.WHITESPACE, Current_char
                    ));
                else if (Commun_values.DIGITS.Contains((char)Current_char))
                    token_list.Add(new Token(
                        TokenTypeName.NUMBER, Current_char
                    ));
                else if (Current_char == '{')
                    token_list.Add(new Token(
                        TokenTypeName.L_CURlY, Current_char
                    ));
                else if (Current_char == '}')
                    token_list.Add(new Token(
                        TokenTypeName.R_CURlY, Current_char
                    ));
                else if (Current_char == '[')
                    token_list.Add(new Token(
                        TokenTypeName.L_SQUARE, Current_char
                    ));
                else if (Current_char == ']')
                    token_list.Add(
                        new Token(TokenTypeName.R_SQUARE, Current_char
                    ));
                else if (Current_char == '"')
                    token_list.Add(
                        new Token(TokenTypeName.DBL_QUOTE, Current_char
                    ));
                else if (re.IsMatch(new string($"{Current_char}")))
                    token_list.Add(
                        new Token(TokenTypeName.DBL_QUOTE, Current_char
                    ));
                else
                    throw new InvalidTokenException("Invalid Token");

                this.Advance();
            }

            return token_list;
        }
    };
}