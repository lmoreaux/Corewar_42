if [ -d "true_cor" ]
then rm true_cor/*
else mkdir true_cor
fi
if [ -d "yours_cor" ]
then rm yours_cor/*
else mkdir yours_cor
fi

cp champs/* true_cor/
cp champs/* yours_cor/

for i in true_cor/**.s
do ./asm_true "$i" &> /dev/null
rm $i
done

for i in yours_cor/**.s
do ./asm "$i" &> /dev/null
rm $i
done

for i in true_cor/**.cor
do
j="$(cut -d'/' -f2 <<<"$i")"
j="yours_cor/$j"
diff "$i" "$j"
done 

for i in yours_cor/**.cor
do
j="$(cut -d'/' -f2 <<<"$i")"
j="true_cor/$j"
diff "$i" "$j"
done
