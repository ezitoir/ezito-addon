


const fs = require("fs");
const path = require("path");
const dir = path.join(__dirname , "deps");
const ezitoCpp = path.join( __dirname , "ezito.cpp");
const writeStream = fs.createWriteStream(ezitoCpp);
 
fs.readdirSync(dir).map(function (file){
    if(!["cpp",".cpp",".cc","cc"].includes(path.extname(file))) return;
    file = path.join(dir , file);
    const buffer =  fs.readFileSync(file ,"utf8").toString();
    writeStream.write(buffer.replace(/#include "ezito.h"/gi , '#include "deps/ezito.h"'));
});

writeStream.close();
