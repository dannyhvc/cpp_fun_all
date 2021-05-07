namespace json_validator
{
    public class Token
    {
        public Token(TokenTypeName t_name, object val)
        {
            type_name = t_name;
            value_object = val;
        }

        public TokenTypeName type_name { get; set; }
        public object value_object { get; set; }
    }
}