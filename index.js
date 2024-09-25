
require("./merge")
const path = require("path"); 
const fs = require("fs");
const sourceDir = path.join(__dirname , "deps");
const includeDir = path.join(__dirname , "deps");
  

module.exports.include_dir = (function(){
    const root = process.cwd();
    const include_dir = includeDir.slice(root.length).replace(/\\/g , "/"); 
    return  (include_dir[0] == "/" ? include_dir.slice(1) : include_dir);
})();

module.exports.include = fs.readdirSync(sourceDir).map( function(src){ 
    if(["cpp",".cpp",".cc","cc"].includes(path.extname(src))){ 
        return path.join(__dirname , "deps" ,src).replace(/\\/g , "/");
    } 
}).filter(function(src) {
    return src != undefined;
});


module.exports.sources = module.exports.include .map( function(src){ 
    if(["cpp",".cpp",".cc","cc"].includes(path.extname(src))){
        const root = process.cwd();
        const sourceFile = src.slice(root.length).replace(/\\/g , "/");
        return  (sourceFile[0] == "/" ? sourceFile.slice(1) : sourceFile);
    }
}).filter(function(src) {
    return src != undefined;
}).join(" ");

 

module.exports.ezito = (function(){
    const root = process.cwd();
    const sourceFile = path.join(__dirname , "ezito.cpp").slice(root.length).replace(/\\/g , "/");
    return  (sourceFile[0] == "/" ? sourceFile.slice(1) : sourceFile);
})();
module.exports.source = module.exports.ezito;