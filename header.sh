if [ $# -ne 1 ]
	then
	echo "usage: $0 <class_name>"
	exit 0
fi
name=$1
cname="${name}.class.cpp"
hname="${name}.class.hpp"

# Add standard headers
vim "$hname" -c "Stdheader" -c "wq"

# Delete 13 line from .h file
sed -i.bak -e '13d' "$hname"
rm "$hname.bak"

upper_name=$(echo "$name" | tr '[:lower:]' '[:upper:]')
# 
echo "#ifndef ${upper_name}_CLASS_H" >> "$hname"
echo "# define ${upper_name}_CLASS_H" >> "$hname"
echo "" >> "$hname"
echo "class ${name}
{ 
public:
${name}();
~${name}();
private:

};
" >> "$hname"
echo "#endif" >> "$hname"

# Add standard headers
vim "$cname" -c "Stdheader" -c "wq"

# Delete 13 line from .cpp file
sed -i.bak -e '13d' "$cname"
rm "$cname.bak"

echo "#include \"${hname}\"" >> "$cname"