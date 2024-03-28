let lineDataArr = [];

function saveLastestData(data) {
    //console.log(data);    
    var buff = new Buffer.from(data, 'utf-8');
    var buffStr = buff.toString('hex');
    var dataArr = [];
    //console.log('buffStr:'+buffStr);
    for (var i = 0; i < buffStr.length ; i++)
        if(i%2==0)
            dataArr.push(buffStr.substring(i,i+2));
    
    for(idx in dataArr){
        lineDataArr.push(dataArr[idx]);
        if(dataArr[idx] == '7e') {
            timer_upload_data_make(lineDataArr);
            lineDataArr = [];
        }
    }
}

function timer_upload_data_make(dataArray) {
  console.log('[dataArray]', typeof dataArray, dataArray);
  console.log('[dataArray[0]]', typeof dataArray[0], dataArray[0]);
}

const data = Buffer.alloc(100);
data.write('Hello, world!');
data[1] = 126;
console.log('[data]', typeof data, data);
saveLastestData(data);
