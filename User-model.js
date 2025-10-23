import mongoose, {Schema} from "mongoose";
import bcrypt from "bcrypt"
import jwt from "jsonwebtoken"


const userSchema = new Schema({
    username : {
        type : String,
        required : true,
        unique : true,
        lowercase : true,
        trim : true,
        index : true
    },  
    email : {
        type : String,
        required : true,
        unique : true,
        lowercase : true,
        trim : true,
    },
    fullName : {
        type : String,
        required : true,
        trim : true,
        index : true
    },
    avatar : {
        type : String,  //cloudinary url
        required : true,
    },
    coverImage : {
        type : String
    },
    watchHistory : {
        type : Schema.Types.ObjectId,
        ref: "Video",
    },
    username : {
        type : String,
        required : true,
        unique : true,
    },
    password : {
        type : String,
        required : [true, "Password is required"]
    },
    refreshToken : {
        type : String
    }
},{ timestamps : true })

//ye user ka password save karta ha aur jab humne kuch aur changes kare ho jase image ,name to ye sidhe next kar deta ha 
userSchema.pre("save", async function (next) {
    if(!this.isModified("password")) return next();
    
    //new password aya ha hash me store karta ha rounds hum kitne bhi de sakte ha (10)
    this.password = await bcrypt.hash(this.password, 10)
    next()
})

//yaha humne aak naya method banaya ha jo password ko check karega
userSchema.methods.isPasswordCorrect = async function(password){
    return await bcrypt.compare(password, this.password)
}

userSchema.methods.generateAccessToken = function(){
    return jwt.sign(
        {
            _id : this._id,
            email : this.email,
            username : this.username,
            fullName : this.fullName
        },
        process.env.ACCESS_TOKEN_SECRET,
        {
            expiresIn : process.env.ACCESS_TOKEN_EXPIRY
        }
    )
} 

userSchema.methods.generateRefreshToken = function(){
    return jwt.sign(
        {
            _id : this._id,
        },
        process.env.REFRESH_TOKEN_SECRET,
        {
            expiresIn : process.env.REFRESH_TOKEN_EXPIRY
        }
    )
} 

export const User = mongoose.model("User" , userSchema);
