$(document).ready(function(){
    $(".aboutContent").hide();
    
    $(".film").mouseenter(function(){
    },
    function(){
        $(".aboutContent").fadeIn(2000);
    })
    
    $(".film").mouseenter(function(){
    },
    function(){
        $(".film").animate({opacity:0.8}, 1500);
    })
    

})


