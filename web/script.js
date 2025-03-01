let loc_now  = "Iwade";
let loc_dest = "Miyamae";

function changeLocation(){
  [loc_now, loc_dest] = [loc_dest, loc_now];
  document.getElementById("locations").textContent = loc_now + " to " + loc_dest;

  // if(loc_now === "Iwade"){
  //   document.getElementById("locations").textContent = "Miyamae to Iwade";
  // }else{
  //   document.getElementById("locations").textContent = "Iwade to Miyamae";
  // }
  
  // console.log("changeLocation()");
}

function update(){
  document.getElementById("leave-1").  textContent = "8:10";
  document.getElementById("arrive-1"). textContent = "9:10";
  document.getElementById("waiting-1").textContent = "9:10";
  document.getElementById("leave-1"). style.color = "#FF831F";
  document.getElementById("arrive-1").style.color = "#FF831F";
  document.getElementById("iwade-1").   style.flex = 1;
  document.getElementById("wakayama-1").style.flex = 1;
  document.getElementById("miyamae-1"). style.flex = 1;
}

leave-1
arrive-1
waiting-1